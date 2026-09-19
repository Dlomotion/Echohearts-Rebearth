import type { Metadata } from "next";
import "./globals.css";

export const metadata: Metadata = {
  title: {
    default: "ECHOHEARTS: REBEARTH",
    template: "%s | ECHOHEARTS: REBEARTH",
  },
  description:
    "Official development website for ECHOHEARTS: REBEARTH, an open-world creature-bonding survival-restoration RPG.",
};

export default function RootLayout({ children }: Readonly<{ children: React.ReactNode }>) {
  return (
    <html lang="en">
      <body>{children}</body>
    </html>
  );
}
