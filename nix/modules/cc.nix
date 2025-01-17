{ pkgs, ... }:

{
  packages = [
    pkgs.ninja
    pkgs.gcc
    pkgs.openssl
    pkgs.binutils
    pkgs.cmake
    pkgs.gtest
    pkgs.gdb
  ];
}
