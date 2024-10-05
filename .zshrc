# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="robbyrussell"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

alias mini='~/mini-moulinette/mini-moul.sh'

alias gpush="git add . ; git commit -m 'Ahoy~ !'; git push"
alias Fnormi="sh ~/better_norminette.sh"
vgcl() {
    git clone git@github.com:"$1"/"$2" "${@:3}"
}

alias t="make test || make re; clear ; echo '\033[1;92mMAKE TEST : DONE\033[0m' ; ls"
alias c="make clean ; clear ; echo '\033[1;92mMAKE CLEAN : DONE\033[0m' ; ls"
alias f="make fclean ; clear ; echo '\033[1;92mMAKE FCLEAN : DONE\033[0m' ; ls"
alias n="make norminette ; echo '\033[1;92mMAKE NORMINETTE : DONE\033[0m' ; ls"
alias debug="make debug"

alias s="git status"
alias poule="git pull"
alias pull="git pull"
alias francinette=/home/mgallais/francinette/tester.sh
alias paco=/home/mgallais/francinette/tester.sh
alias paco_rabanne=/home/mgallais/francinette/tester.sh

alias echoval="echo '\033[1;92mval = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --keep-debuginfo=yes\033[0m\n'"
alias val="echoval ; valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --keep-debuginfo=yes"
alias valong="val --suppressions=./mlx42.supp"
alias vashell="val --suppressions=./rl.supp"
alias vafork="val --child-silent-after-fork=yes"

export PATH="/home/mgallais/sgoinfre/node-v20.12.2-linux-x64/bin:$PATH"


alias re="exec zsh"

# Welcome message
clear
echo -n "\033[1;36m"
# Get the current terminal width
term_width=$(( $(tput cols) - 2 ))

# Create the top and bottom borders
border=$(printf '─%.0s' $(seq 1 $term_width))

# Create the welcome message centered
message="│ Welcome, DailyWind to your ZSH shell ! │"
padding=$(( (term_width - ${#message} - 1) / 2 ))
if [ $((term_width % 2)) -eq 0 ]; then
    padded_message=$(printf "│\033[1;37m%*s%s%*s  \033[1;36m│" $padding '' "$message" $padding '')
else
    padded_message=$(printf "│\033[1;37m%*s%s%*s \033[1;36m│" $padding '' "$message" $padding '')
fi

# Print the border, message, and border again
echo "╭$border╮"
echo "│$(printf '%*s' "$term_width")│"
echo "$padded_message"
echo "│$(printf '%*s' "$term_width")│"
echo "╰$border╯"

#echo "+------------------------------------------------------------------------------------------------------+"
#echo "|                                                                                                      |"
#echo -n "|    "; echo -n "\033[1;37m| "; echo -n "\033[0;36m"; echo -n "Welcome,"; echo -n "\033[1;37m"; echo -n " DailyWind"; echo -n "\033[0;36m"; echo -n " to your ZSH shell !"; echo -n "\033[1;36m"; echo "                                                          |"
#echo "|                                                                                                      |"
#echo "+------------------------------------------------------------------------------------------------------+"
echo -n "\033[1;33m"
echo -n "> Currently in : "
echo -n "\033[1;31m"
echo $PWD
if [ -d ./.git ]; then
    echo -n "\033[1;92m"
    echo -n "> Git : "
    echo -n "\033[1;0m"
    git pull
fi
echo -n "\033[1;0m"
ls
# ---
