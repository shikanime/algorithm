{
  perSystem = _: {
    treefmt = {
      programs = {
        clang-format.enable = true;
        cmake-format.enable = true;
      };
      settings.global.excludes = [
        "algorithm-cc/share/*"
      ];
    };
    devenv.shells.cc.imports = [
      ../devenv/cc.nix
    ];
  };
}
