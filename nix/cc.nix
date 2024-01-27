{ pkgs, ... }:

{
  pre-commit.hooks.clang-format.enable = true;
  packages = [
    pkgs.ninja
    pkgs.gcc
    pkgs.openssl
    pkgs.binutils
    pkgs.cmake
    pkgs.gtest
    pkgs.cmake-format
    pkgs.clang-tools
    pkgs.gdb
  ];
}
