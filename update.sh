#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

# Update gitignore
gitnr create \
  ghc:Nix \
  repo:shikanime/gitignore/refs/heads/main/Devenv.gitignore \
  tt:c \
  tt:c++ \
  tt:elixir \
  tt:erlang \
  tt:jetbrains+all \
  tt:linux \
  tt:macos \
  tt:node \
  tt:ocaml \
  tt:python \
  tt:vim \
  tt:visualstudiocode \
  tt:windows >.gitignore

# Update workflows
bash "$(dirname "$0")"/.github/workflows/update.sh 2>&1 |
  sed 's/^/['workflows'] /'
