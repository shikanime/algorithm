{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation {
  name = "algorithm-shell";
  buildInputs = [
    pkgs.elixir
    pkgs.nodejs
    pkgs.opam
    pkgs.zip
    pkgs.ninja
    pkgs.cmake
    pkgs.gnumake
    pkgs.clang-tools
  ];
}
