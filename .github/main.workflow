workflow "Linux Engine compilaiton" {
  on = "push"
  resolves = ["linux-engine-compilaiton"]
}

workflow "Linux Game compilaiton" {
  on = "push"
  resolves = ["linux-game-compilaiton"]
}

action "linux-engine-compilaiton" {
  uses = "victorneuret/epitech-cmake-action@0.1"
  args = "engine"
}

action "linux-game-compilaiton" {
  uses = "victorneuret/epitech-cmake-action@0.1"
  args = "game"
}
