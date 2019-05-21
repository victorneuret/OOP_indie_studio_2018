FROM epitechcontent/epitest-docker

LABEL "com.github.actions.name"="Linux engine compilation"
LABEL "com.github.actions.description"="Compile the game engine on linux using the epitch docker image"
LABEL "com.github.actions.icon"="aperture"
LABEL "com.github.actions.color"="purple"

RUN dnf -y install irrlicht

ADD entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]