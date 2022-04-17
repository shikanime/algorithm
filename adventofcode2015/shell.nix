{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.clang_14
    pkgs.clang-tools
    pkgs.openssl
  ];
}
