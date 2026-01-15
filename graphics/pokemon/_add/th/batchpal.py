import os
import re
from PIL import Image

OUT_COLORS = 16

def detect_palette(path):
    with Image.open(path) as img:
        if img.mode != "P":
            img = img.convert(
                "P",
                palette=Image.ADAPTIVE,
                colors=256
            )

        raw = img.getpalette()
        used = img.getcolors(256)
        if not used:
            return []

        idxs = sorted(i for _, i in used)

        return [
            (raw[i*3], raw[i*3+1], raw[i*3+2])
            for i in idxs
        ]

def write_jasc_16(colors, path):
    out = list(colors[:OUT_COLORS])
    while len(out) < OUT_COLORS:
        out.append((0, 0, 0))

    with open(path, "wb") as f:
        f.write(b"JASC-PAL\r\n0100\r\n16\r\n")
        for r, g, b in out:
            f.write(f"{r} {g} {b}\r\n".encode("ascii"))

def mass_convert():
    n_re = re.compile(r"([ _]N|^N)\.PNG$", re.I)
    s_re = re.compile(r"([ _]S|^S)\.PNG$", re.I)

    for root, _, files in os.walk("."):
        for name in files:
            full = os.path.join(root, name)

            if n_re.search(name):
                pal = detect_palette(full)
                if pal:
                    write_jasc_16(
                        pal,
                        os.path.join(root, "normal.pal")
                    )
                    print(
                        f"{root}/normal "
                        f"= {len(pal)} colors"
                    )

            elif s_re.search(name):
                pal = detect_palette(full)
                if pal:
                    write_jasc_16(
                        pal,
                        os.path.join(root, "shiny.pal")
                    )
                    print(
                        f"{root}/shiny "
                        f"= {len(pal)} colors"
                    )

if __name__ == "__main__":
    mass_convert()
