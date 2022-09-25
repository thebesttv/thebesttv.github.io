if [[ $# -ne 2 ]]; then
    echo "Usage: $0 l r"
    exit 1
else
    echo "Setting up $1..$2"
fi

SOURCE=setup.org

for i in $(eval echo "{$1..$2}"); do
    TARGET=setup-${i}.org
    # https://stackoverflow.com/a/38868864
    printf -v rep '%*s' "$i"
    res=${rep// /../}

    echo $TARGET $res

    sed "s|{REPLACE-ME}|${res}|" $SOURCE > $TARGET
done
