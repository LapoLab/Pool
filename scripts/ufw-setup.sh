#!/bin/bash

declare -a arr=(
	3333
	3339
	3334
	3433
	3555
)

sudo ufw default deny incoming
    sudo ufw default allow outgoing
    sudo ufw allow ssh
    sudo ufw allow http
    sudo ufw allow https
	sudo ufw allow 3333/tcp
	sudo ufw allow 3339/tcp
	sudo ufw allow 3334/tcp
	sudo ufw allow 3433/tcp
	sudo ufw allow 3555/tcp
	sudo ufw allow 3556/tcp
	sudo ufw allow 3573/tcp
	sudo ufw allow 3535/tcp
	sudo ufw allow 3533/tcp
	sudo ufw allow 3553/tcp
	sudo ufw allow 3633/tcp
	sudo ufw allow 3733/tcp
	sudo ufw allow 3636/tcp
	sudo ufw allow 3737/tcp
	sudo ufw allow 3739/tcp
	sudo ufw allow 3747/tcp
	sudo ufw allow 3833/tcp
	sudo ufw allow 3933/tcp
	sudo ufw allow 4033/tcp
	sudo ufw allow 4133/tcp
	sudo ufw allow 4233/tcp
	sudo ufw allow 4234/tcp
	sudo ufw allow 4333/tcp
	sudo ufw allow 4433/tcp
	sudo ufw allow 4533/tcp
	sudo ufw allow 4553/tcp
	sudo ufw allow 4633/tcp
	sudo ufw allow 4733/tcp
	sudo ufw allow 4833/tcp
	sudo ufw allow 4933/tcp
	sudo ufw allow 5033/tcp
	sudo ufw allow 5133/tcp
	sudo ufw allow 5233/tcp
	sudo ufw allow 5333/tcp
	sudo ufw allow 5433/tcp
	sudo ufw allow 5533/tcp
	sudo ufw allow 5733/tcp
	sudo ufw allow 5743/tcp
	sudo ufw allow 3252/tcp
	sudo ufw allow 5755/tcp
	sudo ufw allow 5766/tcp
	sudo ufw allow 5833/tcp
	sudo ufw allow 5933/tcp
	sudo ufw allow 6033/tcp
	sudo ufw allow 5034/tcp
	sudo ufw allow 6133/tcp
	sudo ufw allow 6233/tcp
	sudo ufw allow 6333/tcp
	sudo ufw allow 6433/tcp
	sudo ufw allow 7433/tcp
	sudo ufw allow 8333/tcp
	sudo ufw allow 8463/tcp
	sudo ufw allow 8433/tcp
	sudo ufw allow 8533/tcp
    sudo ufw --force enable






ports = [
	3333,
	3339,
	3334,
	3433,
	3555,
	3556,
	3573,
	3535,
	3533,
	3553,
	3633,
	3733,
	3636,
	3737,
	3739,
	3747,
	3833,
	3933,
	4033,
	4133,
	4233,
	4333,
	4533,
	4553,
	4633,
	4733,
	4833,
	4933,
	5033,
	5433,
	5533,
	5733,
	3743,
	3252,
	5755,
	5833,
	5933,
	6033,
	5034,
	6133,
	6233,
	6333,
	6433,
	7433,
	8333,
	8463,
	8433,
	8533
]

