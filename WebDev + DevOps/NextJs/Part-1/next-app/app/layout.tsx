
import "./globals.css";


export default function RootLayout({ children }: LayoutProps<"/">) {
  return (
    <html
      lang="en"
      className={`h-full antialiased`}
    >
      <body className="min-h-full flex flex-col">
        <div className="border-2 p-5 m-5 ">
          Trello
        </div>
        {children}
        </body>
    </html>
  );
}
