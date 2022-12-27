{ pkgs, ... }:

{
  pre-commit.hooks = {
    black.enable = true;
    isort.enable = true;
  };
  packages = [
    (pkgs.python3.withPackages (ps: with ps; [
      poetry
      pip
    ]))
  ];
}
