{ pkgs ? import <nixpkgs> { } }:

let
  pythonEnv = pkgs.python3.withPackages (pypkgs: [
    pypkgs.pip
    pypkgs.black
    pypkgs.pytest
  ]);
in
pkgs.mkShell {
  buildInputs = [
    pkgs.elixir
    pkgs.deno
    pkgs.nodejs
    pkgs.opam
    pkgs.zip
    pkgs.ninja
    pkgs.cmake
    pkgs.clang
    pkgs.gmock
    pkgs.gnumake
    pkgs.cmake-format
    pkgs.clang-tools
    pythonEnv
  ];
}
