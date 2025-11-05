{ inputs, pkgs, ... }:

{
  cachix = {
    enable = true;
    push = "shikanime";
  };
  github.enable = true;
  gitignore = {
    enable = true;
    enableDefaultTemplates = true;
  };
  languages = {
    nix.enable = true;
    shell.enable = true;
  };
  packages = [
    pkgs.nushell
    pkgs.sapling
  ];
}
