{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  nativeBuildInputs = [
    pkgs.gcc11
  ];
  buildInputs = [
    pkgs.ninja
    pkgs.cmake
    pkgs.clang-tools
    pkgs.openssl
  ];
}
