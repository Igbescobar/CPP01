#!/usr/bin/env bash
set -eo pipefail
# Cleanup function
cleanup() {
    cd ..
    rm -rf "$TMPDIR"
}
trap cleanup EXIT
BIN=../replacer
TMPDIR=./_testdir
rm -rf "$TMPDIR"
mkdir -p "$TMPDIR"
cd "$TMPDIR"

# helper
fail() { echo "FAIL: $1"; exit 1; }
ok() { echo "OK: $1"; }

# T1: missing args
if "$BIN" 2>/dev/null; then fail "T1: accepted missing args"; else ok "T1"; fi

# T2: empty s1
echo "hello" > t2.txt
if "$BIN" t2.txt "" x >/dev/null 2>/dev/null; then fail "T2: accepted empty s1"; else ok "T2"; fi

# T3: missing input file
if "$BIN" nofile.txt a b >/dev/null 2>/dev/null; then fail "T3: accepted missing input"; else ok "T3"; fi

# T4: s1 not found
printf "hello\n" > t4.txt
"$BIN" t4.txt foo bar
cmp -s t4.txt t4.txt.replace || fail "T4: files differ"; ok "T4"

# T5: basic replace
printf "abc abc\n" > t5.txt
"$BIN" t5.txt abc X
grep -q "X X" t5.txt.replace || fail "T5: replacement failed"; ok "T5"

# T6: s1 == s2 (should be no-op)
printf "repeat\n" > t6.txt
"$BIN" t6.txt repeat repeat
cmp -s t6.txt t6.txt.replace || fail "T6: s1==s2 produced change"; ok "T6"

# T7: overlapping
printf "aaaa\n" > t7.txt
"$BIN" t7.txt aa b
[ "$(cat t7.txt.replace)" = "bb" ] || fail "T7: overlapping behavior wrong"; ok "T7"

# T8: unreadable file
printf "x\n" > t8.txt
chmod 000 t8.txt
if "$BIN" t8.txt a b >/dev/null 2>/dev/null; then fail "T8: accepted unreadable file"; else ok "T8"; fi
chmod 644 t8.txt

# Clean up
cd ..
echo "All tests completed"