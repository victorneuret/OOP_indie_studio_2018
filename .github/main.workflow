workflow "Linux Engine compilaiton" {
  on = "push"
  resolves = ["linux-engine-compilation"]
}

workflow "Linux Game compilaiton" {
  on = "push"
  resolves = ["linux-game-compilation"]
}

action "linux-engine-compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  args = "engine"
}

action "linux-game-compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  args = "bomberman"
}
