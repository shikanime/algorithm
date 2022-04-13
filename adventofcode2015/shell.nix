{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.clang
    pkgs.clang-tools
    pkgs.openssl
  ];
}
