{ pkgs, ... }:

{
  containers = pkgs.lib.mkForce { };
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
  languages.nix.enable = true;
  packages = [
    pkgs.gh
  ];
}
