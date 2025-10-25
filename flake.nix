{
  description = "Miryoku Babel - Generate layer data for Miryoku implementations";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        miryoku-babel = pkgs.stdenv.mkDerivation {
          pname = "miryoku-babel";
          version = "0.1.0";

          src = ./.;

          nativeBuildInputs = with pkgs; [
            emacs
            python3
          ];

          buildPhase = ''
            # Tangle the org file to generate all target configs
            emacs --batch -Q \
              -f package-initialize \
              -eval "(require 'ob-python)" \
              -eval "(setq org-confirm-babel-evaluate nil)" \
              -eval "(setq python-indent-guess-indent-offset-verbose nil)" \
              ./readme.org \
              -f org-babel-tangle
          '';

          installPhase = ''
            mkdir -p $out/share/miryoku_babel

            # Copy all tangled output
            cp -r tangled/* $out/share/miryoku_babel/

            # Also copy the source files for reference
            mkdir -p $out/share/doc/miryoku_babel
            cp readme.org $out/share/doc/miryoku_babel/
            cp custom_config.h $out/share/doc/miryoku_babel/ || true
          '';

          meta = with pkgs.lib; {
            description = "Generate layer data for Miryoku keyboard layout implementations";
            homepage = "https://github.com/manna-harbour/miryoku_babel";
            license = licenses.gpl3;
          };
        };

      in {
        packages = {
          default = miryoku-babel;
          miryoku-babel = miryoku-babel;
        };

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            emacs
            python3
          ];

          shellHook = ''
            echo "Miryoku Babel development environment"
            echo "Run: emacs readme.org   # to edit the source"
            echo "Run: nix build          # to generate all configs"
          '';
        };
      }
    );
}
