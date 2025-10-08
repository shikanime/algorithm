{
  perSystem = _: {
    treefmt = {
      programs.mix-format.enable = true;
      settings.global.excludes = [
        "algorithm-beam/priv/*"
      ];
    };
    devenv.shells.beam.imports = [
      ../devenv/beam.nix
    ];
  };
}
