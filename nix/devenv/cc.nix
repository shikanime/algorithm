{ pkgs, ... }:

{
  gitignore.templates = [
    "tt:c"
    "tt:c++"
  ];
  packages = [
    pkgs.ninja
    pkgs.gcc
    pkgs.openssl
    pkgs.binutils
    pkgs.cmake
    pkgs.gtest
  ];
}
