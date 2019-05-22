workflow "Linux Engine compilaiton" {
  on = "push"
  resolves = ["github.com/victorneuret/epitech-cmake-action"]
}

action "github.com/victorneuret/epitech-cmake-action" {
  uses = "victorneuret/epitech-cmake-action@0.1"
  args = "engine"
}
