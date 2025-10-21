{ inputs, pkgs, ... }:

{
  cachix = {
    enable = true;
    push = "shikanime";
  };
  containers = pkgs.lib.mkForce { };
  github.enable = true;
  languages = {
    nix.enable = true;
    shell.enable = true;
  };
  packages = [
    pkgs.sapling
  ];
}
