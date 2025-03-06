#include <iostream>
#include <memory>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Абстрактные продукты
class Folder {
public:
    virtual void create() const = 0;
    virtual std::string getPath() const = 0;
    virtual ~Folder() = default;
};

class File {
public:
    virtual void create() const = 0;
    virtual ~File() = default;
};

// Конкретные продукты
class ConcreteFolder : public Folder {
    std::string path;
public:
    ConcreteFolder(const std::string& name) : path(name) {}

    void create() const override {
        if (!fs::exists(path)) {
            fs::create_directory(path);
            std::cout << "Folder created: " << path << std::endl;
        }
    }

    std::string getPath() const override {
        return path;
    }
};

class TextFile : public File {
    std::string filePath;
public:
    TextFile(const std::string& path) : filePath(path) {}

    void create() const override {
        std::ofstream file(filePath);
        file << "This is a text file";
        std::cout << "Text file created: " << filePath << std::endl;
    }
};

class BinaryFile : public File {
    std::string filePath;
public:
    BinaryFile(const std::string& path) : filePath(path) {}

    void create() const override {
        std::ofstream file(filePath, std::ios::binary);
        char data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // "Hello" в ASCII
        file.write(data, sizeof(data));
        std::cout << "Binary file created: " << filePath << std::endl;
    }
};

// Абстрактная фабрика
class FileSystemFactory {
public:
    virtual std::unique_ptr<Folder> createFolder(const std::string& name) const = 0;
    virtual std::unique_ptr<File> createTextFile(const std::string& path) const = 0;
    virtual std::unique_ptr<File> createBinaryFile(const std::string& path) const = 0;
    virtual ~FileSystemFactory() = default;
};

// Конкретная фабрика
class ConcreteFileSystemFactory : public FileSystemFactory {
public:
    std::unique_ptr<Folder> createFolder(const std::string& name) const override {
        return std::make_unique<ConcreteFolder>(name);
    }

    std::unique_ptr<File> createTextFile(const std::string& path) const override {
        return std::make_unique<TextFile>(path);
    }

    std::unique_ptr<File> createBinaryFile(const std::string& path) const override {
        return std::make_unique<BinaryFile>(path);
    }
};

void createFileSystem(const FileSystemFactory& factory) {
    
    auto folder = factory.createFolder("bom_bom");
    folder->create();

    auto textFile = factory.createTextFile(folder->getPath() + "/file1.txt");
    auto binaryFile = factory.createBinaryFile(folder->getPath() + "/file2.bin");

    textFile->create();
    binaryFile->create();
}

int main() {
    ConcreteFileSystemFactory factory;
    createFileSystem(factory);
    return 0;
}