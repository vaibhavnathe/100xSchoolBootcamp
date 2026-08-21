

export default function RootLayout({ children }: LayoutProps<"/">) {
  return (
   <div>
    <h1>Auth Layout Page</h1>
    {children}
   </div>
  );
}
