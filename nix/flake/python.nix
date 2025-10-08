{
  perSystem = _: {
    treefmt = {
      programs = {
        ruff-format.enable = true;
        taplo.enable = true;
      };
      settings.global.excludes = [
        "*.jinja2"
        "*.python-version"
      ];
    };
    devenv.shells.python.imports = [
      ../devenv/python.nix
    ];
  };
}
