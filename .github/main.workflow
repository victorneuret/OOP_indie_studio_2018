workflow "Linux compilaiton" {
  on = "push"
  resolves = ["Linux Game compilation"]
}

action "Linux Engine compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  args = "engine"
}

action "Linux Game compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  needs = ["Linux Engine compilation"]
  args = "bomberman"
}
