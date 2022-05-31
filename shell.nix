{ pkgs ? import <nixpkgs> { } }:

pkgs.gccStdenv.mkDerivation {
  name = "algorithm";
  buildInputs = [
    pkgs.elixir
    pkgs.nodejs
    pkgs.opam
    pkgs.yarn
    pkgs.zip
    pkgs.ninja
    pkgs.cmake
    pkgs.gnumake
    pkgs.clang-tools
  ];
}
