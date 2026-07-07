#!/bin/bash
s=() n=0
while IFS= read -r l || [[ -n "$l" ]]; do
    ((n++))

    o=$(grep -o "{" <<< "$l" | wc -l)
    c=$(grep -o "}" <<< "$l" | wc -l)

    if (( c > 0 && ${#s[@]} > 0 )); then
        start=${s[-1]}
    else
        start=$n
    fi

    for ((i=0; i<c; i++)); do
        if (( ${#s[@]} > 0 )); then unset 's[-1]'; fi
    done

    for ((i=0; i<o; i++)); do
        s+=($n)
    done

    h=$(sed -n "${start},${n}p" "$1" | sed '/^#/d' | cpp -dD -P -fpreprocessed 2>/dev/null | tr -d '[:space:]' | md5sum | cut -c-3)

    printf "%s %s\n" "$h" "$l"
done < "$1"
