{ pkgs, ... }:

{
  containers = pkgs.lib.mkForce { };
  languages.nix.enable = true;
  cachix = {
    enable = true;
    push = "shikanime";
  };
  git-hooks.hooks = {
    actionlint.enable = true;
    deadnix.enable = true;
    flake-checker.enable = true;
    shellcheck.enable = true;
  };
  packages = [
    pkgs.gh
  ];
}
