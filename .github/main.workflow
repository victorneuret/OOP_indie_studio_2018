workflow "Linux Engine compilaiton" {
  on = "push"
  resolves = ["./actions/linux-engine-compilation"]
}

action "./actions/linux-engine-compilation" {
  uses = "victorneuret/epitech-cmake-action@0.1"
  args = "engine"
}
