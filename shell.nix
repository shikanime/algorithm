{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.elixir
    pkgs.nodejs
    pkgs.opam
    pkgs.ninja
    pkgs.cmake
    pkgs.gcc
    pkgs.gmock
    pkgs.openssl
    pkgs.gnumake
    pkgs.gdb
    pkgs.cmake-format
    pkgs.clang-tools
    pkgs.nixpkgs-fmt
    (pkgs.python3.withPackages (pypkgs: with pypkgs; [
      pip
      poetry
    ]))
  ];
}
