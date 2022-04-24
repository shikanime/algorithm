{ pkgs ? import <nixpkgs> { } }:

pkgs.gcc11Stdenv.mkDerivation {
  name = "adventofcode2015";
  buildInputs = [
    pkgs.ninja
    pkgs.cmake
    pkgs.conan
    pkgs.clang-tools
  ];
}
