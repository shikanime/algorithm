{ pkgs ? import <nixpkgs> { } }:

let
  pythonEnv = pkgs.python3.withPackages (pypkgs: [
    pypkgs.black
  ]);
in
pkgs.stdenv.mkDerivation {
  name = "algorithm-shell";
  buildInputs = [
    pkgs.elixir
    pkgs.deno
    pkgs.nodejs
    pkgs.opam
    pkgs.zip
    pkgs.ninja
    pkgs.cmake
    pkgs.gnumake
    pkgs.clang-tools
    pythonEnv
  ];
}
