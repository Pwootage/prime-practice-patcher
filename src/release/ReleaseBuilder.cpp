#include "ReleaseBuilder.hpp"

#include "../fs.hpp"
#include <logvisor/logvisor.hpp>

#define FATAL(msg) { fprintf(stderr, msg); return 1; }

using namespace fs;
using namespace std;

int build_release(std::vector<std::string> args) {
  if (args.size() < 1) FATAL("Must provide at least one positional argument (the length)\n");
  string version = args[0];

  printf("Producing a new release: version %s\n", version.c_str());

  path cwd = current_path();

  path scriptPath = absolute(cwd / ".." / "prime-practice-script");
  printf("Script directory: %s\n", scriptPath.string().c_str());
  if (!is_directory(scriptPath)) FATAL("Script directory does not exist!\n");

  path nativePath = absolute(cwd / ".." / "prime-practice-native");
  printf("Native directory: %s\n", nativePath.string().c_str());
  if (!is_directory(nativePath)) FATAL("Native directory does not exist!\n");

  path isoPath = absolute(cwd / "GM8E01.iso");
  printf("ISO Path: %s\n", isoPath.string().c_str());
  if (!is_regular_file(isoPath)) FATAL("ISO doesn't exist!\n");

  path buildDir = absolute(cwd / "release" / version);
  path releaseDir = absolute(buildDir / ("prime-practice-" + version));
  path releaseResDir = absolute(releaseDir / "release");
  printf("Output directory: %s\n", buildDir.string().c_str());
  printf("Release directory: %s\n", releaseDir.string().c_str());
  printf("Release res directory: %s\n", releaseResDir.string().c_str());

  remove_all(buildDir);
  create_directories(buildDir);
  create_directories(releaseDir);
  create_directories(releaseResDir);

  // yeah yeah yeah I know system is ultra insecure, this is ONLY used on packaging
  // TODO: don't use system and be secure
  printf("Running script build\n");
  path scriptBuildPath = absolute(scriptPath / "compile_prod.sh");
  current_path(scriptPath);
  system(scriptBuildPath.string().c_str());
  current_path(cwd);

  printf("Running native build\n");
  path nativeBuildPath = absolute(nativePath / "compile.sh");
  current_path(nativePath);
  system(nativeBuildPath.string().c_str());
  current_path(cwd);

  printf("Copying mod.js\n");
  copy_file(
    scriptPath / "dist" / "mod.js",
    releaseResDir / "mod.js"
  );

  printf("Copying Mod.rel\n");
  copy_file(
    nativePath / "build" / "Mod.rel",
    releaseResDir / "Mod.rel"
  );

  printf("Copying DolPatch.bin\n");
  copy_file(
    cwd / "res" / "DolPatch.bin",
    releaseResDir / "DolPatch.bin"
  );

  printf("Copying opening_practice.bnr\n");
  copy_file(
    cwd / "res" / "opening_practice.bnr",
    releaseResDir / "opening_practice.bnr"
  );

  printf("Copying patcher\n");
  copy_file(
    cwd / "res" / "prime_practice_patcher_linux",
    releaseDir / "prime_practice_patcher_linux"
  );
  copy_file(
    cwd / "res" / "prime_practice_patcher_macos",
    releaseDir / "prime_practice_patcher_macos"
  );
  copy_file(
    cwd / "res" / "prime_practice_patcher_windows.exe",
    releaseDir / "prime_practice_patcher_windows.exe"
  );
  copy_file(
    cwd / "./patch.sh",
    releaseDir / "./patch.sh"
  );
  copy_file(
    cwd / "./patch.bat",
    releaseDir / "./patch.bat"
  );
  copy_file(
    cwd / "./README.md",
    releaseDir / "./README.md"
  );

  printf("Creating release zip\n");
  current_path(buildDir);
  path outZip = absolute(buildDir / ("prime-practice-" + version + ".zip"));
  path releaseDirRelative = relative(releaseDir, buildDir);
  string command = "zip -r \"" + outZip.string() + "\" \"" + releaseDirRelative.string() + "\"";
  printf("Executing: %s\n", command.c_str());
  system(command.c_str());
  current_path(cwd);

  return 0;
}
