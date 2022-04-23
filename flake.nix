{
  description = "My algorithms sketchbook";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/release-21.11";

  outputs = { self, nixpkgs, home-manager, ... }: {
    devShells = nixpkgs.lib.genAttrs nixpkgs.lib.platforms.unix
      (system: {
        adventOfCode2015 =
          import ./adventofcode2015/shell.nix { pkgs = import nixpkgs { inherit system; }; };
        adventOfCode2019 =
          import ./adventofcode2019/shell.nix { pkgs = import nixpkgs { inherit system; }; };
        hashcode2020 =
          import ./hashcode2020/shell.nix
            { pkgs = import nixpkgs { inherit system; }; };
        hashcode2022 =
          import ./hashcode2022/shell.nix
            { pkgs = import nixpkgs { inherit system; }; };
        crackTheCodeInterviewElixir =
          import ./crackthecodeinterview/elixir/shell.nix
            { pkgs = import nixpkgs { inherit system; }; };
        crackTheCodeInterviewNode =
          import ./crackthecodeinterview/node/shell.nix
            { pkgs = import nixpkgs { inherit system; }; };
      });
  };
}
