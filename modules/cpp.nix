{ pkgs, ... }:

{
  pre-commit.hooks.clang-format.enable = true;
  packages = [
    pkgs.ninja
    pkgs.gcc
    pkgs.cmake
    pkgs.openssl
    pkgs.gmock
    pkgs.cmake-format
    pkgs.clang-tools
    pkgs.gdb
  ];
}
