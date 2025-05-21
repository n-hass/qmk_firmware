{
  description = "Python environment with specific requirements using python3.withPackages";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        python = pkgs.python3;
        pythonEnv = python.withPackages (ps: with ps; [
          appdirs
          argcomplete
          colorama
          dotty-dict
          hidapi  # 'hid' is typically provided via 'hidapi'
          hjson
          jsonschema
          milc
          pygments
          pyserial
          pyusb
          pillow
        ]);
      in {
        devShell = pkgs.mkShell {
          buildInputs = [
            pythonEnv
            pkgs.qmk
          ];
          shellHook = ''
            export QMK_HOME=$(pwd)
            zsh
          '';
        };

        packages.default = pythonEnv;
      }
    );
}
