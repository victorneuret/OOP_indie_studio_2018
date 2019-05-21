workflow "Linux Engine compilaiton" {
  on = "push"
  resolves = ["./actions/linux-engine-compilation"]
}

action "./actions/linux-engine-compilation" {
  uses = "victorneuret/OOP_indie_studio_2018/@feature/Engine-CI-linux/actions/linux-engine-compilation"
}