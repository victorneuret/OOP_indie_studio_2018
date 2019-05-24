workflow "Linux compilaiton" {
  on = "push"
  resolves = ["Game compilation"]
}

action "Engine compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  args = "engine"
}

action "Game compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  needs = ["Engine compilation"]
  args = "bomberman"
}
