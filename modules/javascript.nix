{ pkgs, ... }:

{
  pre-commit.hooks.prettier.enable = true;
  packages = [
    pkgs.nodejs
  ];
}
