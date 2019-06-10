workflow "Linux Continuous Integration" {
  resolves = ["Linux unit tests"]
  on = "push"
}

action "Linux compilation" {
  uses = "victorneuret/epitech-cmake-action/compile@v2"
  args = "bomberman"
}

action "Linux unit tests" {
  uses = "victorneuret/epitech-cmake-action/unit_tests@v2"
  needs = "Linux compilation"
  args = "tests_run --verbose -j1"
}
