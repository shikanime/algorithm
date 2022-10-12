{ pkgs ? import <nixpkgs> { } }:

let
  pythonEnv = pkgs.python3.withPackages (pypkgs: with pypkgs; [
    pip
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
    pkgs.gcc
    pkgs.gmock
    pkgs.poetry
    pkgs.gnumake
    pkgs.gdb
    pkgs.cmake-format
    pkgs.clang-tools
    pythonEnv
  ];
}
