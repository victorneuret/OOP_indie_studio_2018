workflow "Linux compilaiton" {
  on = "push"
  resolves = ["Linux compilation"]
}

action "Linux compilation" {
  uses = "victorneuret/epitech-cmake-action@v1"
  args = "bomberman"
}
