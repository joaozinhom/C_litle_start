{
  description = "C development shell with GCC 11+";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";
 
  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          packages = [
            pkgs.libgcc
            pkgs.gdb
            pkgs.gnumake42
            pkgs.pkg-config
          ];
          shellHook = ''
            echo "Welcome, my brother, to your C dev shell with GCC >=11!"
            gcc --version
          '';
        };
      }
    );
}