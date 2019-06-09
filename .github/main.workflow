workflow "Linux compilaiton" {
  on = "push"
  resolves = ["Linux Unit Tests"]
}

action "Linux compilation" {
  uses = "victorneuret/epitech-cmake-action/compile@v2"
  args = "bomberman"
}

action "Linux Unit Tests" {
  uses = "victorneuret/epitech-cmake-action/unit_tests@v2"
  needs = ["Linux compilation"]
  args = "tests_run"
}
