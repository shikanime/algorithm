{ pkgs ? import <nixpkgs> { } }:

let
  vscode = {
    cmakeKits = pkgs.writeText "cmake-kits.json" (builtins.toJSON [
      {
        name = "Nix";
        environmentVariables = {
          CMAKE_MAKE_PROGRAM = "${pkgs.ninja}/bin/ninja";
          CMAKE_INCLUDE_PATH = builtins.concatStringsSep ":"
            [
              "${pkgs.libcxx.dev}/include"
              "${pkgs.libcxxabi.dev}/include"
              "${pkgs.openssl.dev}/include"
            ];
          CMAKE_LIBRARY_PATH = builtins.concatStringsSep ":"
            [
              "${pkgs.libcxx}/lib"
              "${pkgs.libcxxabi}/lib"
              "${pkgs.openssl.out}/lib"
            ];
          CMAKE_C_COMPILER = "${pkgs.gcc11}/bin/gcc";
          CMAKE_CXX_COMPILER = "${pkgs.gcc11}/bin/g++";
          CMAKE_EXPORT_COMPILE_COMMANDS = "ON";
        };
      }
    ]);
    settings = pkgs.writeText "settings.json" (builtins.toJSON {
      "cmake.cmakePath" = "${pkgs.cmake}/bin/cmake";
      "cmake.ctestPath" = "${pkgs.cmake}/bin/ctest";
    });
  };
in
pkgs.mkShell
{
  nativeBuildInputs = [
    pkgs.gcc11
  ];
  buildInputs = [
    pkgs.ninja
    pkgs.cmake
    pkgs.clang-tools
    pkgs.openssl
  ];
  shellHook = ''
    cp -rf ${vscode.cmakeKits} .vscode/cmake-kits.json
    cp -rf ${vscode.settings} .vscode/settings.json
  '';

}
