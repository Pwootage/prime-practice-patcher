import * as yargs from 'yargs';
import * as fs from 'fs-extra';
import {ReleaseCommand} from "./commands/ReleaseCommand";
import {PatchCommand} from "./commands/PatchCommand";
import {logger} from "./Logger";
import * as path from "path";

const pkgJson = fs.readJSONSync(path.resolve(process.cwd() , './package.json'));

export function main() {
  logger.info(`Prime Practice Mod Patcher v${pkgJson.version}`);
  const args = yargs
    .command(new ReleaseCommand())
    .command(new PatchCommand())
    .help('h')
    .alias('h', 'help')
    .option('verbose', {
      alias: 'v',
      default: 0,
      description: 'More verbose output (can be repeated)',
      count: true
    })
    .check((argv, aliases) => {
      logger.setVerbosity(argv.verbose || 0);
      return true;
    }, true)
    .demandCommand()
    .recommendCommands()
    .argv;
}