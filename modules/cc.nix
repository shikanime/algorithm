{ pkgs, ... }:

{
  pre-commit.hooks.clang-format.enable = true;
  packages = [
    pkgs.ninja
    pkgs.gcc
    pkgs.binutils
    pkgs.cmake
    pkgs.openssl
    pkgs.gtest
    pkgs.cmake-format
    pkgs.clang-tools
    pkgs.gdb
  ];
}
