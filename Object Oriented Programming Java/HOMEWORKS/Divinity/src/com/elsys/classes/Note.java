package com.elsys.classes;

public class Note extends Item {
    String text;

    public Note(String name, String text) {
        try {
            if (name == null || name.length() < 3) {
                throw new Exception("Name should be at least 3 characters long!");
            }
            if (text == null || text.length() < 10) {
                throw new Exception("Name should be at least 10 characters long!");
            }
            this.name = name;
            this.text = text;
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public String getText() {
        return text;
    }
}
