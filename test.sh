#!/usr/bin/env bash
center() {
    termwidth="$(tput cols)"
    padding="$(printf '%0.1s' -{1..500})"
    printf '%*.*s \e[36m%s\e[0m %*.*s\n' 0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"
}

help() {
    cat << EOF
Usage: $0 [OPTION]...
Simple kattis test runner.

General help using GNU software: <http://www.gnu.org/gethelp/>
EOF
}

base() {
    PROGRAM="$1"
    PREFIX="src"
    BASE="$PREFIX/$PROGRAM"
    echo "$BASE"
}

main() {
    PROGRAM="$1"
    BASE="$(base $PROGRAM)"

    # test base directory
    [ ! -d "$BASE" ] && continue

    # Test exist and executable
    [ ! -x "$PROGRAM" ] && continue

    # Try all executables
    for txt in "$BASE/"*.{txt,in}; do
        if [ -s "$txt" ]; then
            echo
            echo

            center "${txt##*/}"
            # (
                # pr -t -m \
                # <(echo -e "\e[35mInput\e[0m"; cat "$txt") \
                # <(echo -e "\e[32mOutput\e[0m"; "./$PROGRAM" < "$txt")
                "./$PROGRAM" <"$txt"
            # ) 2> >(while read line; do echo -e "\e[31m$line\e[0m" >&2; done)
            printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
        fi
    done
}

fetch() {
    KATTIS="https://open.kattis.com"

    PROGRAM="$1"
    BASE="$(base $PROGRAM)"

    # Create directory structure
    mkdir -p "$BASE"
	cp --no-clobber template.h "$BASE/$PROGRAM.cpp"
	touch "$BASE/$PROGRAM"{1..9}.txt

    tmp="$(mktemp)"
    tmpdir="${tmp}_extract"
    url="$KATTIS/problems/$PROGRAM/file/statement/samples.zip"
    echo "Fetch $url"
    curl -fsSL -o "$tmp" "$url" || return 1

    mkdir -p "$tmpdir"
    unzip "$tmp" -d "$tmpdir" >/dev/null 2>&1

    count=1
    for i in "$tmpdir"/*.in; do
        output="$BASE/$PROGRAM$count.txt"
        echo "$i => $output"
        cp "$i" "$output"
        count=$((count+1))
    done

    rm -rf "$tmpdir" "$tmp"
}



if [ $# -eq 0 ]; then
    help
    exit 0
fi


until [ $# -eq 0 ]; do
    if [ ${1:0:1} == "+" ]; then
        fetch ${1:1} || echo "Error fetch ${1:1}"
    else
        main "$1"
    fi
    shift
done

